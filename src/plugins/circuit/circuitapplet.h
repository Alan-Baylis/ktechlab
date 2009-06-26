/***************************************************************************
 *   Copyright (C) 2009 Julian Bäume <julian@svg4all.de>                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef CIRCUITAPPLET_H
#define CIRCUITAPPLET_H

#include <Plasma/Containment>
#include <Plasma/DataEngine>
#include <Plasma/FrameSvg>

namespace Plasma
{
class Theme;
} // namespace Plasma

class QString;
class QStringList;
class QGraphicsSceneDragDropEvent;

class ComponentApplet;

class CircuitApplet: public Plasma::Containment
{
    Q_OBJECT
public:
    CircuitApplet( QObject *parent, const QVariantList &args = QVariantList() );
    ~CircuitApplet();

    void init();

    virtual void dropEvent( QGraphicsSceneDragDropEvent *event );

    void paintInterface(QPainter *painter,
            const QStyleOptionGraphicsItem *option,
            const QRect& contentsRect);

public slots:
    void dataUpdated( const QString &name, const Plasma::DataEngine::Data &data );

private:
    void setCircuitName( const QString &name );
    QString circuitName() const;

    void setupData();
    QString m_circuitName;
    QString m_componentTheme;
    QMap<QString,ComponentApplet*> m_components;

    QSizeF m_componentSize;

    Plasma::Theme *m_theme;
    Plasma::FrameSvg m_bg;
};

#endif

