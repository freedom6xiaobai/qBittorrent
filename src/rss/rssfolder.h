/*
 * Bittorrent Client using Qt4 and libtorrent.
 * Copyright (C) 2010  Christophe Dumez, Arnaud Demaiziere
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * In addition, as a special exception, the copyright holders give permission to
 * link this program with the OpenSSL project's "OpenSSL" library (or with
 * modified versions of it that use the same license as the "OpenSSL" library),
 * and distribute the linked executables. You must obey the GNU General Public
 * License in all respects for all of the code used other than "OpenSSL".  If you
 * modify file(s), you may extend this exception to your version of the file(s),
 * but you are not obligated to do so. If you do not wish to do so, delete this
 * exception statement from your version.
 *
 * Contact: chris@qbittorrent.org, arnaud@qbittorrent.org
 */

#ifndef RSSFOLDER_H
#define RSSFOLDER_H

#include <QHash>

#include "rssfile.h"

class RssArticle;
class DownloadThread;
class RssFeed;

class RssFolder: public RssFile, public QHash<QString, RssFile*> {
  Q_OBJECT

public:
  RssFolder(RssFolder *parent = 0, QString name = QString());
  ~RssFolder();
  RssFolder* parent() const { return m_parent; }
  void setParent(RssFolder* parent) { m_parent = parent; }
  unsigned int unreadCount() const;
  FileType type() const;
  RssFeed* addStream(QString url);
  RssFolder* addFolder(QString name);
  unsigned int getNbFeeds() const;
  QList<RssFile*> getContent() const;
  QList<RssFeed*> getAllFeeds() const;
  QHash<QString, RssFeed*> getAllFeedsAsHash() const;
  QString displayName() const;
  QString id() const;
  bool hasChild(QString ID);
  QList<RssArticle> articleList() const;
  QList<RssArticle> unreadArticleList() const;
  void removeAllSettings();
  void removeAllItems();

public slots:
  void refresh();
  void addFile(RssFile * item);
  void removeFile(QString ID);
  void setAlias(const QString &new_name);
  void markAsRead();

private:
  RssFolder *m_parent;
  QString m_name;
};

#endif // RSSFOLDER_H
