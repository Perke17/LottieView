#include "lottiemodel.h"

#include <QDir>

LottieModel::LottieModel(QAbstractListModel *parent) : QAbstractListModel(parent)
{

}

QVariant LottieModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)
    // meh
//    if (index.row())
    return m_homeDir + QDir::separator() + m_lottieFiles[index.row()];
}

int LottieModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_lottieFiles.length();
}

void LottieModel::resetList()
{
    beginResetModel();
    QDir dir(homeDir());
    m_lottieFiles.clear();
    if (dir.exists())
    {
        QStringList onlyJson;
        onlyJson << ".json";
        m_lottieFiles = dir.entryList(QDir::Files);
    }
    endResetModel();
}

void LottieModel::setHomeDir(QString homeDir)
{
    if (m_homeDir != homeDir)
    {
        m_homeDir = homeDir;
        resetList();
        emit homeDirChanged();
    }
}
