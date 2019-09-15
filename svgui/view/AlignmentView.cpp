/* -*- c-basic-offset: 4 indent-tabs-mode: nil -*-  vi:set ts=8 sts=4 sw=4: */

/*
    Sonic Visualiser
    An audio file viewer and annotation editor.
    Centre for Digital Music, Queen Mary, University of London.
    This file copyright 2006-2014 Chris Cannam and QMUL.
    
    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of the
    License, or (at your option) any later version.  See the file
    COPYING included with this distribution for more information.
*/

#include "AlignmentView.h"

#include <QPainter>

#include "data/model/SparseOneDimensionalModel.h"

#include "layer/TimeInstantLayer.h"

using std::vector;

AlignmentView::AlignmentView(QWidget *w) :
    View(w, false),
    m_above(nullptr),
    m_below(nullptr)
{
    setObjectName(tr("AlignmentView"));
}

void
AlignmentView::globalCentreFrameChanged(sv_frame_t f)
{
    View::globalCentreFrameChanged(f);
    update();
}

void
AlignmentView::viewCentreFrameChanged(View *v, sv_frame_t f)
{
    View::viewCentreFrameChanged(v, f);
    if (v == m_above) {
        m_centreFrame = f;
        update();
    } else if (v == m_below) {
        update();
    }
}

void
AlignmentView::viewManagerPlaybackFrameChanged(sv_frame_t)
{
    update();
}

void
AlignmentView::viewAboveZoomLevelChanged(ZoomLevel level, bool)
{
    m_zoomLevel = level;
    update();
}

void
AlignmentView::viewBelowZoomLevelChanged(ZoomLevel, bool)
{
    update();
}

void
AlignmentView::setViewAbove(View *v)
{
    if (m_above) {
        disconnect(m_above, nullptr, this, nullptr);
    }

    m_above = v;

    if (m_above) {
        connect(m_above,
		SIGNAL(zoomLevelChanged(ZoomLevel, bool)),
                this, 
		SLOT(viewAboveZoomLevelChanged(ZoomLevel, bool)));
    }
}

void
AlignmentView::setViewBelow(View *v)
{
    if (m_below) {
        disconnect(m_below, nullptr, this, nullptr);
    }

    m_below = v;

    if (m_below) {
        connect(m_below,
		SIGNAL(zoomLevelChanged(ZoomLevel, bool)),
                this, 
		SLOT(viewBelowZoomLevelChanged(ZoomLevel, bool)));
    }
}

void
AlignmentView::paintEvent(QPaintEvent *)
{
    if (m_above == nullptr || m_below == nullptr || !m_manager) return;

    bool darkPalette = false;
    if (m_manager) darkPalette = m_manager->getGlobalDarkBackground();

    QColor fg, bg;
    if (darkPalette) {
        fg = Qt::gray;
        bg = Qt::black;
    } else {
        fg = Qt::black;
        bg = Qt::gray;
    }

    QPainter paint(this);
    paint.setPen(QPen(fg, 2));
    paint.setBrush(Qt::NoBrush);
    paint.setRenderHint(QPainter::Antialiasing, true);

    paint.fillRect(rect(), bg);

    vector<sv_frame_t> keyFrames = getKeyFrames();

    foreach (sv_frame_t f, keyFrames) {
        int ax = m_above->getXForFrame(f);
        sv_frame_t rf = m_above->alignToReference(f);
        sv_frame_t bf = m_below->alignFromReference(rf);
        int bx = m_below->getXForFrame(bf);
        paint.drawLine(ax, 0, bx, height());
    }

    paint.end();
}

vector<sv_frame_t>
AlignmentView::getKeyFrames()
{
    if (!m_above) {
        return getDefaultKeyFrames();
    }

    ModelId m;

    // get the topmost such
    for (int i = 0; i < m_above->getLayerCount(); ++i) {
        if (qobject_cast<TimeInstantLayer *>(m_above->getLayer(i))) {
            ModelId mm = m_above->getLayer(i)->getModel();
            if (ModelById::isa<SparseOneDimensionalModel>(mm)) {
                m = mm;
            }
        }
    }

    auto model = ModelById::getAs<SparseOneDimensionalModel>(m);
    if (!model) {
        return getDefaultKeyFrames();
    }

    vector<sv_frame_t> keyFrames;

    EventVector pp = model->getAllEvents();
    for (EventVector::const_iterator pi = pp.begin(); pi != pp.end(); ++pi) {
        keyFrames.push_back(pi->getFrame());
    }

    return keyFrames;
}

vector<sv_frame_t>
AlignmentView::getDefaultKeyFrames()
{
    vector<sv_frame_t> keyFrames;

    if (!m_above || !m_manager) return keyFrames;

    sv_samplerate_t rate = m_manager->getMainModelSampleRate();
    if (rate == 0) return keyFrames;

    for (sv_frame_t f = m_above->getModelsStartFrame(); 
         f <= m_above->getModelsEndFrame(); 
         f += sv_frame_t(rate * 5 + 0.5)) {
        keyFrames.push_back(f);
    }
    
    return keyFrames;
}

