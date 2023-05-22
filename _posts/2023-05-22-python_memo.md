---
layout: single
title: pycharm memo
---

pycharm에서 gym을 이용하여 머신러닝 공부를 하고 있는데  
DeprecationWarning: `np.bool8` is a deprecated alias for `np.bool_`.  (Deprecated NumPy 1.24) 이러한 에러가 떴다.  
numpy 일정 버전 이상에서는 bool8 변수를 사용하지 않아서 생기는 경고문구이다.  
무시해도 되지만 거슬린다면  
1. 경고문구를 무시하는 코드를 작성하거나,  
2. np.bool8 이 작성되어있는 해당 파일의 np.bool8 -> bp.bool_ 로 다 바꿔주면 된다.

