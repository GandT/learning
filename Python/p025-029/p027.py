#coding: UTF-8

from datetime import datetime
now = datetime.now()

#月/日/年　の形式　ex) 12/23/2015
print '%s/%s/%s' % (now.month, now.day, now.year)
