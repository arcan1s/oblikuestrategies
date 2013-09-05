/***************************************************************************
 *   Copyright (C) 2013 by Evgeniy Alekseev <esalekseev@gmail.com>         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#ifndef OBLIKUESTRATEGIES_H
#define OBLIKUESTRATEGIES_H

#include <Plasma/Applet>
#include <Plasma/Label>

#include <ui_configwindow.h>

class QGraphicsLinearLayout;

class oblikuestrategies : public Plasma::Applet
{
  Q_OBJECT
public:
  oblikuestrategies(QObject *parent, const QVariantList &args);
  ~oblikuestrategies();
  int setMessagesText();
  void init();

public slots:
  int autoUpdateEvent();
  int sendNotification(QString eventId, int num);
  int updateEvent();
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  // for configuration interface
  int setAutoUpdate();
  void configAccepted();
  void configChanged();

protected:
  void createConfigurationInterface(KConfigDialog *parent);

private:
  // ui
  Plasma::Label *main_label;
  Plasma::Label *info_label;
  QTimer *timer;
  // variables
  bool autoUpdate_bool, notify_bool;
  int autoUpdate_int, edition, fontSize, fontWeight;
  QString fontFamily, fontColor, fontStyle;
  QStringList formatLine, copyright;
  QList<QStringList> mess;
  // configuration interface
  Ui::ConfigWindow uiConfig;
};

K_EXPORT_PLASMA_APPLET(oblikue-strategies, oblikuestrategies)
#endif /* OBLIKUESTRATEGIES_H */
