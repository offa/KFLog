/***********************************************************************
**
**   kflogstartlogo.cpp
**
**   This file is part of KFLog2.
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

#include "kflogstartlogo.h"

#include <kapp.h>
#include <kstddirs.h>

#include <qbitmap.h>
#include <qpixmap.h>

//KFLogStartLogo::KFLogStartLogo()
//    : QWidget( 0, "KFlogStartWindow",  WStyle_Customize | WStyle_StaysOnTop |
//             WStyle_NoBorder )
//{
KFLogStartLogo::KFLogStartLogo()
    : QWidget( 0, "KFlogStartWindow",  WStyle_Customize | WStyle_NoBorder )
{
//  QPixmap pm(locate("appdata", "pics/entwurf_splash.png"));
  QPixmap pm(locate("appdata", "pics/splash.png"));

  setBackgroundPixmap(pm);
  setMask(QBitmap(locate("appdata", "pics/splash_mask.png")));

  QWidget *desktop = KApplication::desktop();
  QRect rect = desktop->geometry();
  move(rect.x() + (rect.width() - pm.width())/2,
       rect.y() + (rect.height() - pm.height())/2);

  setFixedSize(pm.size());
}

KFLogStartLogo::~KFLogStartLogo()
{

}
