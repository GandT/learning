#coding: UTF-8

from datetime import datetime
now = datetime.now()

#独自フォーマットによる日時表記
print '%s/%s/%s %s:%s:%s' % (now.year, now.month, now.day, now.hour, now.minute, now.second)
