#coding: UTF-8
from datetime import datetime
now = datetime.now()

#時:分:秒 の形　ex)12:24:48
print '%s:%s:%s' % (now.hour, now.minute, now.second)
