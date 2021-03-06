<!-- ---
layout: post
title:  "python 자료형 (Data Type) 알아보기 01 - 숫자 자료형"
date:   2021-10-22 10:43:59
author: Gyeom
categories: Development
tags:	[study,python]
cover:  "/assets/python_cover.png"
---
- 
{:toc}
<hr>  

# python Data type, 첫번째 - 숫자 자료형
  
<hr>

자료형을 이야기 하기 전에, 파이썬은 자료형을 따로 지정해주지 않아도 된다는 점이 신기했다.

예를들어 C++ 에서는

``` cpp

int num = 10 // 변수 선언

```

이와같이 C/C++의 경우 변수 선언을 할때 자료형을 꼭 같이 써줘야 한다. 

**하지만**, 파이썬의 경우에는

``` python

num = 10 # 변수 선언

```
위와 같이 변수 선언시 자료형을 따로 알려주지 않아도 된다.

## 숫자 자료형
* 숫자 자료형은 아래와 같은 타입들이 있다.
    * 정수형
    * 실수형
    * 2진수
    * 8진수
    * 16진수 

정수형
: 정수형(integer)이란 말 그대로 정수를 뜻하는 자료형이다. 아래의 예를 보자.

``` python
integer = 10
print(type(integer))
```
의 결과는 ~  

    <class 'int'>
     -->
