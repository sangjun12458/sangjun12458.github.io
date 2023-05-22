---
layout: single
title: 파이썬 메모
---

PyCharm에서 gym을 이용해서 머신러닝을 공부중인데  
  File "경로\파이썬파일.py", line 50, in step ...   
이런 메시지가 여러줄 뜨면서 마지막 줄에
  KeyboardInterrupt
  Process finished with exit code -1073741510 (0xC000013A: interrupted by Ctrl+C)  
이러한 에러가 떳습니다. 
이것은 사용자로부터 이상한 입력을받은 경우에 발생합니다.  
저같은 경우는 머신러닝을 진행중인데 창을 x로 끌때 나왔습니다.  
이러한 경우
1. 그냥 입력하지 않게 조심하거나 (창을 끌 때 PyCharm의 종료버튼을 눌러서 끄기)
2. 사용자 입력에 관련된 코드를 작성해줘야 합니다.
