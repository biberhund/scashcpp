#ifndef SENDCOINSDIALOG_H
#define SENDCOINSDIALOG_H

#include <QtWidgets/QDialog>
#include <QString>
#include <QTimer>

namespace Ui {
    class SendCoinsDialog;
}
class WalletModel;
class SendCoinsEntry;
class SendCoinsRecipient;

QT_BEGIN_NAMESPACE
class QUrl;
QT_END_NAMESPACE

/** Dialog for sending bitcoins */
class SendCoinsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SendCoinsDialog(QWidget *parent = 0);
    ~SendCoinsDialog();

    void setModel(WalletModel *model);

    /** Set up the tab chain manually, as Qt messes up the tab chain by default in some cases (issue https://bugreports.qt-project.org/browse/QTBUG-10907).
     */
    QWidget *setupTabChain(QWidget *prev);

    void pasteEntry(const SendCoinsRecipient &rv);
    bool handleURI(const QString &uri);

    void coinControlFeatureDisplayToggle();

public slots:
    void clear();
    void reject();
    void accept();
    SendCoinsEntry *addEntry();
    void updateRemoveEnabled();
    void setBalance(qint64 balance, qint64 stake, qint64 unconfirmedBalance, qint64 immatureBalance);

    void updateOnTimer();

private:
    Ui::SendCoinsDialog *ui;
    WalletModel *model;
    bool fNewRecipientAllowed;
    bool fCoinControlShow;
    QWidget *messageEntry;
    QTimer* timer;

    void processSendStuff(bool bursting = false);

private slots:
    void on_sendButton_clicked();
    void on_toggleCoinControlButton_clicked();
    void on_messageButton_clicked();
    void removeEntry(SendCoinsEntry* entry);
    void updateDisplayUnit();
    void coinControlFeatureChanged(bool);
    void coinControlButtonClicked();
    void coinControlChangeChecked(int);
    void coinControlChangeEdited(const QString &);
    void coinControlUpdateLabels();
    void coinControlClipboardQuantity();
    void coinControlClipboardAmount();
    void coinControlClipboardFee();
    void coinControlClipboardAfterFee();
    void coinControlClipboardBytes();
    void coinControlClipboardPriority();
    void coinControlClipboardLowOutput();
    void coinControlClipboardChange();
    void on_burstSendButton_clicked();
};

#endif // SENDCOINSDIALOG_H
