/**
 * Copyright (C) 2016 Deepin Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 **/

#ifndef USERMODEL_H
#define USERMODEL_H

#include <QObject>
#include <QMap>

#include "user.h"

class UserModel : public QObject
{
    Q_OBJECT
public:
    UserModel(QObject *parent = 0);
    ~UserModel();

    User * getUser(const QString &id);
    void addUser(const QString &id, User *user);
    void removeUser(const QString &id);

signals:
    void userAdded(User *user);
    void userRemoved(User *user);

private:
    QMap<QString, User *> m_userList;
};

#endif // USERMODEL_H
