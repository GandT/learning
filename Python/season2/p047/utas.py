# coding: utf-8
import re
class UTCourse:
    def __init__(self, dic):
        for k, v in dic.items():
            if "year" == k:
                self.year = int(v)
            elif "title_j" == k or "name_j" == k:
                v = re.sub(r"[ \u3000]+","\u3000",v)
                setattr(self, k, v)
            else:
                setattr(self, k, v)
