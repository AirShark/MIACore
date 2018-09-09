// Copyright (c) 2015-2018 The MIA developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MIA_QT_EULA_H
#define MIA_QT_EULA_H

#include <QDialog>

namespace Ui {
class Eula;
}

class Eula : public QDialog
{
    Q_OBJECT

public:
    explicit Eula(QWidget *parent = 0);
    ~Eula();
    
    bool isEulaRemembered();
    static void showDialog();
    
private slots:
    void on_cancel_clicked();
    void on_next_clicked();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Eula *ui;
    bool isRemembered;
};

#endif // MIA_QT_EULA_H
