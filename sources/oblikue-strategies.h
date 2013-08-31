/***************************************************************************
 *   Copyright (C) %{CURRENT_YEAR} by %{AUTHOR} <%{EMAIL}>                            *
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

// Here we avoid loading the header multiple times
#ifndef OBLIKUESTRATEGIES_HEADER
#define OBLIKUESTRATEGIES_HEADER

#include <KIcon>
// We need the Plasma Applet headers
#include <Plasma/Applet>
#include <Plasma/Svg>
#include <Plasma/Label>
#include <Plasma/PushButton>
#include <ui_configwindow.h>

class QSizeF;

// Define our plasma Applet
class oblikuestrategies : public Plasma::Applet
{
  Q_OBJECT
public:
  // Basic Create/Destroy
  oblikuestrategies(QObject *parent, const QVariantList &args);
  ~oblikuestrategies();
  void init();

protected:
  void createConfigurationInterface(KConfigDialog *parent);

public slots:
  void updateEvent();
  void configAccepted();
  void configChanged();

private:
  Plasma::Label *m_label;
  Plasma::PushButton *m_button;
  int edition, fontSize, fontWeight;
  QString fontFamily, fontColor, fontStyle;
  QStringList formatLine;
  QStringList mess_first, mess_second, mess_third, mess_fouth;
  Ui::ConfigWindow uiConfig;
};

// This is the command that links your applet to the .desktop file
K_EXPORT_PLASMA_APPLET(oblikue-strategies, oblikuestrategies)
#endif
