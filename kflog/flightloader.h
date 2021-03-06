/***********************************************************************
**
**   flightloader.h
**
**   This file is part of KFLog.
**
**   This class reads a flight file into the memory.
**
************************************************************************
**
**   Copyright (c):  2008 by Constantijn Neeteson
**                   2011-2014 by Axel Pauli
**
**   This file is distributed under the terms of the General Public
**   License. See the file COPYING for more information.
**
***********************************************************************/

#ifndef FLIGHT_LOADER_H
#define FLIGHT_LOADER_H

#include <QObject>

#include <QFile>
#include <QFileInfo>
#include <QHash>

class FlightLoader : public QObject
{
  Q_OBJECT

  private:

  Q_DISABLE_COPY ( FlightLoader )

  public:

  FlightLoader( QObject *parent=0 );

  virtual ~FlightLoader();

   /**
   * Loads a new flight-file.
   *
   * @param  file  The path to the file
   * @return "true", when the file has successfully been loaded
   */
  bool openFlight(QFile&);

   /**
   * Loads a new flight-file.
   *
   * @param  file  The path to the igc-file
   * @return "true", when the file has successfully been loaded
   */
  bool openIGC(QFile&, QFileInfo&);

   /**
   * Imports a file downloaded with Gardown in DOS
   *
   * @param  file  The path to the Gardown-file
   * @return "true", when the file has successfully been loaded
   */
  bool openGardownFile(QFile&, QFileInfo&);

  private slots:

  void slot_CancelLoad();

  private:

  // Short structure to handle the optional entries in an igc file
  class bOption
  {
    public:
      int begin, length;
      char mnemonic[4];
  };

  /** Flight recorder manufactures. */
  static QHash<QString, QString> m_manufactures;

};

#endif
