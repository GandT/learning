#coding: UTF-8

#語尾設定
pyg = 'ay'

#単語入力を受けつける
original = raw_input('Enter a word:')

#英単語以外を除外
if len(original) > 0 and original.isalpha():
    print original
else:
    print 'empty'

#変換処理    
word = original.lower()
first = word[0]
new_word = word + first + pyg
new_word = new_word[1:len(new_word)]

#表示
print new_word
