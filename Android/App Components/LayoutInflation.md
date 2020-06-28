# 레이아웃 인플레이션
>XML레이아웃에 정의된 내용이 메모리 상에 객체화되는 과정

## 1.setContentView()의 역할
 <li>화면에 나타낼 뷰를 지정한다.
 <li>XML레이아웃의 내용을 메모리 상에 객체화 한다.

    [Reference]
    public void setContentView (int layoutResID)
    public void setContentView (View view[,VeiwGroup.LayoutParams params])

## 2.LayoutInflater
>화면 전체가 아닌 일부 뷰만을 위한 XML 레이아웃을 메모리 상에 객체화
 <li>시스템 서비스로 제공하는 방법

    [Reference]
    View inflate (int resource, ViewGroup root, boolean attachToRoot)

 위 메소드의 첫 번째 파라미터는 XML레이아웃 리소스 지정 값, 두 번째 파라미터는
뷰들을 객체화하여 추가할 대상이 되는 부모 컨테이너이다.

 <li>LayoutInflater 클래스에 정의된 form() 메소드를 사용하는 방법

    [Reference]
    static LayoutInflater LayoutInflater.from (Context context)

 <li>내부적으로 지원하는 View의 클래스 메소드를 이용하는 방법

    [Reference]
    static View inflate (Context context, int resource, ViewGroup root)

## 3.레이아웃 객체화 과정의 중요성
애플리케이션이 실행되는 런타임 시에 XML에 정의된 내용들이 메모리 상에 객체화되기 때문이다.
