# coding: UTF-8
"""
　2021.2.5
　Scikit-learn 混合行列とpipenv
　参考文献
　・「評価指標(分類)」 https://aiacademy.jp/texts/show/?id=34
　・「Pythonで、Pipenvを使う」 https://blog.narito.ninja/detail/58/
　・「scikit-learn（sklearn）をmacインストールする方法【pip/conda対応】」 https://dev2prod.site/python/install-scikit-learn/
"""

import sklearn

print("scikit-learn version: ", sklearn.__version__)

y_test      = [0,0,0,0,0,1,1,1,1,1] # 0をNegative 1をPositiveとする
y_predicted = [0,1,0,0,0,0,0,1,1,1] # 機械学習によって予測された値と仮定

from sklearn.metrics import confusion_matrix

# 混合行列を算出
cmatrix = confusion_matrix(y_test, y_predicted)
print(y_test)
print(y_predicted)
print("混合行列")
print(cmatrix)

# Accuracy/正解率を算出
from sklearn.metrics import accuracy_score
tn, fp, fn, tp = confusion_matrix(y_test, y_predicted).ravel() 
accuracy = (tp + tn) / (tp + fp + fn + tn)
print('Accuracy:', accuracy_score(y_test, y_predicted), ' = ', accuracy)

# Precision/適合率を算出
from sklearn.metrics import precision_score
precision = tp / (tp + fp)
print('Precision:', precision_score(y_test, y_predicted), ' = ', precision)

# Recall/再現率を算出
from sklearn.metrics import recall_score
recall = tp / (tp + fn)
print('Recall:', recall_score(y_test, y_predicted), ' = ', recall)

# F値/F1-scoreを算出
from sklearn.metrics import f1_score
f1 = 2 * precision * recall / (precision + recall)
print('F1 score:', f1_score(y_test, y_predicted), ' = ', f1)
