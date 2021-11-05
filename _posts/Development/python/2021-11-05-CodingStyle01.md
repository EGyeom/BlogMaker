---
layout: post
title:  "Python Coding Style을 정하자 chapter 1 !"
date:   2021-11-05 19:43:59
author: Gyeom
categories: Development
tags:	[study,python]
cover:  "/assets/python_cover.png"
---
- 
{:toc}

# Python Coding Style을 정하자!

파이썬으로 코딩을 하기 전에 코드를 작성하는 규칙에 대해 정해야 한다.  

책을 읽다가 좋은 부분이 보여 참고하여 블로그 글을 작성하기로 했다. 

## 인덴트(들여쓰기)

인덴트
: 파이썬은 C++과 다르게 {} 중괄호로 구분하지 않고, 인덴트로 구분하게 된다.  
: if, for나, class, def와 같은 코드 블럭을 작성하면서 나오는 <code>:</code>의 아랫 줄은 반드시 인덴트를 사용해야 한다. 인덴트는 탭이나 칸을 띄어쓰는 방식 등 여러가지 방식이 있지만, 같은 코드블럭 안에서는 동일한 인덴트를 사용해야 한다.  
그렇지 않다면 <code>IndentationError: unexpected indent</code> 에러가 발생한다.

***하지만***,  나는 여기서 파이썬 공식 가이드인 <a href="https://www.python.org/dev/peps/pep-0008/">PEP(Python Enhancement Proposals) 8 </a>에 따라 공백 4칸을 원칙으로 작성하려고 한다.

#### 인덴트 예)

``` python
hello = True
if(hello):
>>>>print("Mocha") # 공백을 '>' 문자로 대체하여 표시했다.
elif:
    print("Latte") # 정상적으로 인덴트를 사용한것
else:
  print("Error") # Error 발생 ! 같은 블록내에 다른 인덴트를 사용함. 
```

## 네이밍 컨벤션 (이름 정하기 규칙)

네이밍컨벤션
: 네이밍 컨벤션이라는것은, 쉽게 말하면 변수명, 함수명과 같은 이름을 통일성 있는 규칙 아래에서 짓도록 이름 정하는 규칙을 세우는 것으로 얘기 할 수 있다.
: 네이밍 컨벤션을 통해 미리 프로젝트 내의 식별자들의 이름을 정했을 경우, 소스코드를 읽는데 수월해지는 장점이있다. (가독성이 좋아진다.)
  
대표적으로 몇가지만 살펴보자.
<hr>

### 1. 카멜 케이스 (Camel Case)
카멜케이스
: 카멜 케이스는 낙타의 등을 비유해서 나타난 네이밍 규칙이다.
: 특징은, 문자 사이사이는 모두 붙여서 쓰고, 첫문자는 소문자, 다음에 나오는 단어의 첫글자는 대문자로 작성한다.

#### 카멜 케이스 예)
``` python
thisIsCamelCase = True 
# 첫문자인 t는 소문자, 다음에 나오는 단어들은 모두 대문자로 시작하는것을 볼수있다.
```
<hr>

### 2. 파스칼 케이스 (Pascal Case)
파스칼케이스
: 파스칼 케이스는 카멜 케이스와 거의 똑같지만, 첫문자도 대문자로 작성하는 것이 특징이다.

#### 파스칼 케이스 예)
``` python
ThisIsPascalCase = True 
# 첫문자인 t도 대문자, 다음에 나오는 단어들도 모두 대문자로 시작하는것을 볼수있다.
```
<hr>

### 3. 스네이크 케이스 (Snake Case)
스네이크 케이스
: 스네이크 케이스는 모양이 뱀과 같다고 하여 네이밍 규칙이다.
: 특징으로는 모든 문자를 소문자로 작성하고, 단어 사이사이에 _(언더바)를 작성한다.
: 파일 명을 작성할때 많이 사용된다.  

#### 스네이크 케이스 예)
``` python
this_is_snake_case = True 
# 모든 문자가 소문자로 표현되고, 단어 사이사이에 _를 넣어 표시하는 것을 볼수있다.
```
<hr>

### 예 모아보기)
``` python
thisIsCamelCase = True # Camel

ThisIsPascalCase = True # Pascal

this_is_snake_case = True #Snake
```
  
위의 내용을 참고하여 자신한테 맞는 네이밍 규칙을 적용하면 된다.
  
스네이크 케이스가 다른 네이밍 규칙보다 더 가독성이 좋다는 이야기가 있기에, 
나의 경우에는 ***스네이크 케이스***를 적용하려고 한다.
  