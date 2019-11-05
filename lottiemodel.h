#ifndef LOTTIEMODEL_H
#define LOTTIEMODEL_H

#include <QAbstractListModel>

class LottieModel : public QAbstractListModel
{
    Q_PROPERTY(QString homeDir READ homeDir WRITE setHomeDir NOTIFY homeDirChanged)

    Q_OBJECT
public:
    explicit LottieModel(QAbstractListModel *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    QString homeDir() const { return m_homeDir; }
    void setHomeDir(QString homeDir);

signals:
    void homeDirChanged();

public slots:

private:
    QString m_homeDir;
    QStringList m_lottieFiles;

    void resetList();
};

#endif // LOTTIEMODEL_H
