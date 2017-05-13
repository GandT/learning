

100.times{ |i|
  ((i * 1290.46 + 340209) / 239 - 483).to_i.times{ print (i+25).chr}
  print "\n"
}
