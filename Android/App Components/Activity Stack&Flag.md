# Activity Stack & Flags
## 1.Activity Stack
액티비티를 순차적으로 쌓아두었다가 가장 상위에 있던 액티비티가 없어지면 이전의 액티비티를 다시 실행하도록 도와준다.

## 2.Flag
> 액티비티라는 화면이 만들어질 때나 보여질 때 어떻게 지시할 것인지를 알려주는 역할을 한다.

    [Reference]
    FLAG_ACTIVITY_SINGLE_TOP
    FLAG_ACTIVITY_NO_HISTORY
    FLAG_ACTIVITY_CLEAR_TOP

- FLAG_ACTIVITY_SINGLE_TOP
 - 액티비티를 생성할 때 이미 생성된 액티비티가 있으면 그 액티비티를 그대로 사용한다.
 - 액티비티가 이미 메모리 상의 객체로 만들어져 있는 경우에는 액티비티를 다시 띄우더라도 onCreate() 메소드가 호출되지 않으므로 onNewIntent() 메소드를 재정의해 사용해야 한다.
    [Reference]
    public void onNewIntent(Intent intent)

- FLAG_ACTIVITY_NO_HISTORY
 - 처음 이후에 실행된 액티비티는 액티비티 스택에 추가되지 않도록 한다.
 - 알람 이벤트가 발생하여 사용자에게 한 번 알람 화면을 보여주고 싶을 때 유용하게 사용할 수 있다.

- FLAG_ACTIVITY_CLEAR_TOP
 - 액티비티 위에 있는 다른 액티비티를 모두 종료시킨다.
 - 홈 화면과 같이 다른 액티비티보다 항상 우선하는 액티비티를 만들 때 유용하게 사용할 수 있다.

