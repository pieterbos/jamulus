/******************************************************************************\
 * Copyright (c) 2004-2020
 *
 * Author(s):
 *  Volker Fischer
 *
 ******************************************************************************
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later 
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more 
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 *
\******************************************************************************/

#pragma once

#include <QLabel>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QMenuBar>
#include <QWhatsThis>
#include <QLayout>
#include <QAccessible>
#include <QDesktopServices>
#include <QMessageBox>
#include "global.h"
#include "util.h"
#include "settings.h"
#include "ui_chatdlgbase.h"


/* Classes ********************************************************************/
class CChatDlg : public CBaseDlg, private Ui_CChatDlgBase
{
    Q_OBJECT

public:
    CChatDlg ( CClientSettings* pNSetP,
               QWidget*         parent = nullptr );

    void AddChatText ( QString strChatText );
    void SaveChatHistory() { pSettings->SaveChat ( slMessageStorage.mid ( std::max ( 0, slMessageStorage.size() - MAX_CHAT_LINES_IN_HISTORY ) ) ); }

protected:
    CClientSettings* pSettings;
    QStringList      slMessageStorage;

public slots:
    void OnSendText();
    void OnLocalInputTextTextChanged ( const QString& strNewText );
    void OnClearChatHistory();
    void OnAnchorClicked ( const QUrl& Url );

signals:
    void NewLocalInputText ( QString strNewText );
};
