/***********************************************************************
**
**   singlepoint.cpp
**
**   This file is part of KFLog.
**
************************************************************************
**
**   Copyright (c):  2000 by Heiner Lamprecht, Florian Ehinger
**
**   This file is distributed under the terms of the General Public
**   Licence. See the file COPYING for more information.
**
**   $Id$
**
***********************************************************************/

#include "singlepoint.h"
#include <mapmatrix.h>

#include <kapp.h>
#include <kiconloader.h>
#include <qdatastream.h>
#include <qfile.h>
#include <qtextstream.h>

SinglePoint::SinglePoint(QString n, QString abbr, unsigned int t,
  QPoint pos, bool wP)
: BaseMapElement(n, t),
  position(pos), isWaypoint(wP), abbrev(abbr)
{
  switch(typeID)
    {
      case UltraLight:
        iconName = "ul.xpm";
        break;
      case HangGlider:
        iconName = "paraglider.xpm";
        break;
      case Parachute:
        iconName = "jump.xpm";
        break;
      case Ballon:
        iconName = "ballon.xpm";
        break;
      case CompPoint:
        iconName = "compoint.xpm";
        break;
      case Oiltank:
        iconName = "oiltank.xpm";
        break;
      case Factory:
        iconName = "factory.xpm";
        break;
      case Castle:
        iconName = "castle.xpm";
        break;
      case Church:
        iconName = "church.xpm";
        break;
      case Tower:
        iconName = "tower.xpm";
        break;
      case HighwayEntry:
        iconName = "highway.xpm";
        break;
      case RailwayBridge:
        iconName = "railbridge.xpm";
        break;
      case Station:
        iconName = "station.xpm";
        break;
      default:
        iconName = "";
        break;
    }
}

SinglePoint::~SinglePoint()
{

}

void SinglePoint::printMapElement(QPainter* printPainter, const double dX,
      const double dY, const int mapCenterLon, const double scale,
      const struct elementBorder mapBorder)
{
  extern const double _scale[];
  extern const bool _showElements[];

  if(!__isVisible()) return;

  struct drawPoint printPos;// = __projectElement(dX, dY, mapCenterLon, scale);

  printPainter->setPen(QPen(QColor(0,0,0), 2));
  char* kflog_dir = "/kflog/map/";
  int iconSize = 16;

  if(scale > _scale[ID_BORDER_SMALL]) {
    kflog_dir = "/kflog/map/small/";
    iconSize = 8;
  }

  QString iconName;
  bool show = true;

  /*
   * Hier sollte mal f�r eine bessere Qualit�t der Icons gesorgt werden.
   * Eventuell kann man die Icons ja hier zeichnen lassen ?!?
   */
  if(iconName == 0) {
    switch(typeID) {
      case Village:
        printPainter->setBrush(QBrush::NoBrush);
        printPainter->drawEllipse(printPos.x - 5, printPos.y - 5, 10, 10);
        return;
      case Dam:
        printPainter->setBrush(QBrush(QColor(0,0,0), QBrush::SolidPattern));
        printPainter->setPen(QPen(QColor(0,0,0), 1));
        return;
      case Lock:
        printPainter->setBrush(QBrush::NoBrush);
        printPainter->setPen(QPen(QColor(0,0,0), 1));
        return;
    }
  }

  show = _showElements[typeID];

//  if(show)
//    printPainter->drawPixmap(printPos.x - iconSize, printPos.y - iconSize,
//              Icon(KApplication::kde_datadir() + kflog_dir + iconName));
}

bool SinglePoint::__isVisible() const
{
  extern const MapMatrix _globalMapMatrix;

  return _globalMapMatrix.isVisible(position);
}

void SinglePoint::drawMapElement(QPainter* targetPainter)
{
  extern const double _currentScale, _scale[];
  extern const bool _showElements[];

//  if(!__isVisible()) {
//    curPos.x = -1000;
//    curPos.y = -1000;
//    return;
//  }

//  curPos = __projectElement(dX, dY, mapCenterLon, _currentScale);

  targetPainter->setPen(QPen(QColor(0,0,0), 2));
  char* kflog_dir = "/kflog/map/";
  int iconSize = 16;

  if(_currentScale > _scale[ID_BORDER_SMALL]) {
    kflog_dir = "/kflog/map/small/";
    iconSize = 8;
  }

  bool show = true;

  if(iconName == 0)
    {
      /* Hier ist eine weitere virtuelle Funktion n�tig, die
       * das Element zeichnet!
       */
      switch(typeID)
        {
          case Village:
            targetPainter->setBrush(QBrush::NoBrush);
            targetPainter->drawEllipse(curPos.x() - 5, curPos.y() - 5, 10, 10);
            return;
          case Dam:
            targetPainter->setBrush(QBrush(QColor(0,0,0), QBrush::SolidPattern));
            targetPainter->setPen(QPen(QColor(0,0,0), 1));
            return;
          case Lock:
            targetPainter->setBrush(QBrush::NoBrush);
            targetPainter->setPen(QPen(QColor(0,0,0), 1));
            return;
        }
    }

  show = _showElements[typeID];

//  if(show)
//    targetPainter->drawPixmap(curPos.x - iconSize, curPos.y - iconSize,
//          Icon(KApplication::kde_datadir() + kflog_dir + iconName));
}

void SinglePoint::setWaypoint(bool isW)
{
  isWaypoint = isW;
}

bool SinglePoint::isWayPoint() const { return isWaypoint; }

QString SinglePoint::getWPName() const { return abbrev; }

QPoint SinglePoint::getPosition() const { return position; }