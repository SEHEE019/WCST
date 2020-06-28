# REST API
---
## 용어 정리

#### 1. API(Application Programming Interface)
: 데이터와 기능의 집합을 제공하여 컴퓨터 프로그램간 상호작용을 촉진하며, 서로 정보를 교환가능 하도록 하는 것.
  * 웹 API는 웹 어플리케이션 개발에서 다른 서비스에 요청을 보내고, 응답을 받기 위해 정의된 명세를 일컫는다.
#### 2. REST(Representational state trasfar) API
: REST API는 자원을 이름으로 구분하여 해당 자원의 상태(정보)를 주고 받는 모든 것을 의미. Resource, Verb, Representation of Resource로 구성.
  - Resource
  : 자원, http uri
  - Verb
  : 자원에 대한 행위, http method
  - Representation of Resource
  : 자원에 대한 행위의 내용, http message pay load
#### 3. OAuth(Valet Key for the Web)
  - 인터넷 사용자들이 비밀번호를 제공하지 않고 다른 웹사이트 상의 자신들의 정보에 대해 웹사이트나 애플리케이션의 접근 권한을 부여할 수 있는 공통적인 수단으로서 사용되는, 접근 위임을 위한 개방형 표준.
  - token
    + Request token
      + Cusumer key/secret 으로 cunsumer를 인증
      + 처음 인증 후 폐기
    + Access token
      + User로부터 권한을 위임받았음을 인증
      + 지속적으로 사용자를 대리하는 토큰(실제 valet key)

## 구성
#### 1. Resource
: REST API는 리소스를 나타낼 때 URI(Uniform Resource Identifier)를 사용. Client는 URI를 이용해서 자원을 지정하고 해당 자원의 상태(정보)에 대한 조작을 Server에 요청.
  * 형태
    - 슬래시(/)는 계층 관계를 나타낼 때 사용.
      + 포워드 슬래시(//)는 경로 내에서 리소스 간의 계층 관계를 나타내는데 사용.
      ex) https://github.com/SEHEE019
    - URI 마지막 문자로 슬래시(/)를 포함하지 않는다.
      + 아무런 의미는 없지만, 혼란을 방지하기 위해 REST API의 마지막 글자에 슬래시를 포함해서는 안된다.
    - 하이픈(-)은 URI 가독성을 높이는데 사용한다.
      + 가독성을 위해 긴 URI에는 하이픈(-)을 사용.
      ex)https://github.com/SEHEE019/random-alarm-service
    - 밑줄( _ )은 사용하지 않는다.
      + 텍스트 뷰어 어플리케이션은 클릭할 수 있다는 표시로 URI에 밑줄을 긋는다. 또한, 글꼴에 따라 밑줄은 보기 어렵거나 문자가 완전히 가려지기도 한다.
    - URI는 소문자로 구성하는 편이 적합하다.
      + RFC 3986은 URI 스키마와 호스트를 제외하고 대소문자를 구별하도록 규정한다.
    - 파일 확장자는 URI에 포함하지 않는다.
      + Accept header를 사용한다.
      Ex) http://restapi.example.com/members/soccer/345/photo.jpg (X)
      Ex) GET / members/soccer/345/photo HTTP/1.1 Host: restapi.example.com Accept: image/jpg (O)
      <br>
  * 표현
    - resource는 동사<명사, 대문자<소문자 사용
    - 도큐먼트(객체 인스턴스나 DB 레코드와 유사 개념) 이름으로는 단수 명사 사용
    - 컬렉션(서버에서 관리하는 디렉터리라는 리소스) 이름으로는 복수 명사 사용
    - 스토어(클라이언트에서 관리하는 리소스 저장소) 이름으로는 복수 명사 사용

#### 2. Verb
: http 프로토콜의 Method를 사용한다.
  * GET
    - action: index/retrieve
    - role: 모든/ 특정 리소스를 조회
  * POST
    - action: create
    - role: 리소스 생성
  * PUT
    - action: update
    - role: 리소스 갱신
  * DELETE
    - action: delete
    - role: 리소스 삭제

#### 3. Representation of Resource
: 클라이언트가 자원의 상태(정보)에 대한 조작을 요청하면 Server는 이에 적절한 응답(Representation)을 보낸다.
  * REST에서 하나의 자원은 JSON, XML, TEXT,RSS 등 여러 형태의 Representation으로 나타내어 질 수 있다.
  * JSON 혹은 XML을 통해 데이터를 주고 받는 것이 일반적이다.

## 응답 상태 코드
  * 1xx: 전송 프로토콜 수준의 정보 교환
  * 2xx: 클라이언트 요청이 성공적으로 수행됨
  * 3xx: 클라이언트는 요청을 완료하기 위해 추가적인 행동을 취해야 함
  * 4xx: 클라이언트의 잘못된 요청
  * 5xx: 서버 측 오류로 인한 상태 코드

## 인증 과정

<center><img width="300" src="pictures/RestApi&OAuth.PNG" title="RestApi&OAuth"></center>

#### 1. Twitter VS Facebook
* Request token
  - Twitter: O
  - Facebook: X
* Access token
  - Twitter: oauth token + oauth token secret
  - Facebook: access token
* Access Scope(접근 범위는 cunsumer가 설정할 수 있다.)
  - Twitter: 신청 시 결정
  - Facebook: 토큰 요청 시 결정
* Redirect URL
  - Twitter: 사전 지정 + 페이지 지정
  - Facebook: 사전 지정 + 페이지 지정
* Token type(공유 시 악의적인 cunsumer를 배제시킬 수 없다.)
  - Twitter: 독립
  - Facebook: 독립
* Signing
  - Twitter: HMAC-SHA1
  - Facebook: X

## REST API example

#### 1. json-Server
:json-server를 이용한 REST-API
```bash
    $ mkdir rest-api-exam && cd rest-api-exam
    $ npm init -y
    $ npm install json-server
```
db.json 파일 생성
```JSON
{
  "books": [
    {"id": 1, "title":"html", "author":"Woozi"},
    {"id": 2, "title":"css", "author":"DK"},
    {"id": 3, "title":"javascript", "author":"S.coops"}
  ]
}
```
npm script를 사용하여 json-server 실행. 아래와 같이 package.json 수정
```JSON
{
  "name":"rest-api-exam",
  "version":"1.0.0",
  "descriptsion":"",
  "scripts":{
    "serve":"json-server --watch db.json --port 5000"
  },
  "dependencies":{
    "json-server":"^0.12.0"
  }
}
```
json-server 실행. 포트는 5000 사용
```bash
$npm run serve
```

#### 2. GET
books 리소스에서 모든 책 조회(index)
```bash
$curl -X GET http://localhost:5000/books
[
  {
    "id":1,
    "title":"html",
    "author":"Woozi"
  },
  {
    "id":2,
    "title":"css",
    "author":"DK"
  },
  {
    "id":3,
    "title":"javascript",
    "author":"S.coops"
  }
]
```
```javascript
var req = new XMLHttpRequest();
req.open('GET','http://localhost:5000/books');
req.send();

req.onreadystatechange = function(e){
  if(req.readyState === XMLHttpRequest.DONE){
    if(req.status === 200){
      console.log(req.responseText);
    }else{
      console.log("Error!");
    }
  }
}
```
books 리소스에서 특정 책을 조회(retrieve)
```bash
$ curl -X GET http://localhost:5000/books/1
{
  "id":1,
  "title":"html",
  "author":"Woozi"
}
```
```javascript
var req = new XMLHttpRequest();
req.open('GET','http://localhost:5000/books/1');
req.send();

req.onreadystatechange = function(e) {
  if(req.readyState === XMLHttpRequest.DONE){
    if(req.status === 200){
      console.log(req.responseText);
    }else{
      console.log("Error!");
    }
  }
}
```
#### 3. POST
books 리소스에 책 생성
```bash
$ curl -X POST http://localhost:5000/books -H "Content-Type: Application/json" -d '{"title":"ES6", "author":"Hoshi"}'
{
  "title":"ES6",
  "author":"Hoshi",
  "id":4
}
```
```javascript
var req = new XMLHttpRequest();
req.open('POST','http://localhost:5000/books');
req.setRequestHeader('Content-Type','application/json');
req.send(JSON.stringify({
  title: "ES6",
  author: "Hoshi"
}));

req.onreadystatechange = function(e){
  if(req.readyState === XMLHttpRequest.DONE){
    console.log(req.responseText);
  }else{
    console.log("Error!");
  }
};
```
#### 4. PUT
books 리소스의 책 타이틀을 "ES6"에서 "ECMAScript6"로 갱신
```bash
$curl -X PUT http://localhost:5000/books/4 -H "Content-Type: application/json" -d '{"title":"ECMAScript6","author":"Hoshi"}'
{
  "title":"ECMAScript6",
  "author":"Hoshi",
  "id":4
}
```
```javascript
var req = new XMLHttpRequest();
req.open('PUT','http://localhost:5000/books/4');
req.setRequestHeader('content-type','application/json');
req.send(JSON.stringify({
  title:"ecmascript",
  author:"Hoshi"
}));

req.onreadystatechange = function(e){
  if(req.readyState === XMLHttpRequest.DONE){
    if(req.status === 2000){
      console.log(req.responseText);
    }else{
      console.log("Error!");
    }
  }
};
```
#### 5. DELETE
books 리소스에서 책 삭제
```bash
$ curl -X DELETE http://localhost:5000/books/4
{}
```
```javascript
var req = new XMLHttpRequest();
req.open('DELETE',' http://localhost:5000/books/4');
req.send();

req.onreadystatechange = function(e){
  if(req.readyState === XMLHttpRequest.DONE){
    if(req.status === 2000){
      console.log(req.responseText);
    }else{
      console.log("Error!");
    }
  }
};
```

## 참고 출처
* https://www.ics.uci.edu/~fielding/pubs/dissertation/rest_arch_style.htm
* https://poiemaweb.com/js-rest-api
* https://gmlwjd9405.github.io/2018/09/21/rest-and-restful.html
* https://hyunalee.tistory.com/1
* https://www.opentutorials.org/module/53/857
