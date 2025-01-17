/*
 * Copyright (C) 2011 ~ 2021 Deepin Technology Co., Ltd.
 *
 * Author:     duanhongyu <duanhongyu@uniontech.com>

 * Maintainer: duanhongyu <duanhongyu@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "interface/namespace.h"
#include "modules/authentication/charamangermodel.h"
#include "modules/authentication/widgets/faceinfowidget.h"

#include <DSuggestButton>
#include <DAbstractDialog>
#include <DTipLabel>

#include <QObject>

QT_BEGIN_NAMESPACE
class QVBoxLayout;
class QPushButton;
class QCloseEvent;
class QLabel;
QT_END_NAMESPACE

namespace dcc {
namespace authentication {
class FaceInfoWidget;
}
}

namespace DCC_NAMESPACE {
namespace authentication {

// 人脸视频录入对话框
class FaceInfoDialog : public DTK_WIDGET_NAMESPACE::DAbstractDialog
{
    Q_OBJECT
public:
    explicit FaceInfoDialog(dcc::authentication::CharaMangerModel *model, QWidget *parent = nullptr);
    ~FaceInfoDialog();

    inline dcc::authentication::FaceInfoWidget* faceInfoLabel() { return m_faceLabel; }

private:
    void initWidget();

private Q_SLOTS:
    void refreshExplainTips(QString tips);

Q_SIGNALS:
    void requestCloseDlg();

protected:
    void closeEvent(QCloseEvent *event) override;
    bool eventFilter(QObject *o, QEvent *e) override;

private:
    dcc::authentication::CharaMangerModel *m_faceModel;
    dcc::authentication::FaceInfoWidget *m_faceLabel;

    QVBoxLayout *m_mainLayout;
    QLabel *m_explainTips; // 状态说明信息
};

}
}
