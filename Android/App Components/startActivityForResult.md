# startActivityForResult

## 1.용도
<li>단순히 액티비티를 띄워주는 것이 아니라 어떤 액티비티를 띄운 것인지
그리고 띄웠던 액티비티로부터의 응답을 받아 처리하는 코드가 필요할 때
사용한다.
<li>하나의 액티비티에서 다른 액티비티를 띄우기만 하는 것은 상관없지만 띄웠던 액티비티에서 원래의 택티비티로 응답을 보내온다면
새로 띄웠던 여러 액티비티 중에 어던 것으로부터 온 응답인지 구분할 필요가 있기 때문에 이 메소드를
사용하는 경우가 많다.

## 2.startActivityForResult()

    [Reference]
    startActivityForResult(Intent intent, int requestCode)

startActivityForResult() 메소드에 전달되는 파라미터는 인텐트와 정수로 된 코드 값인데
이 코드 값은 일반적으로 각각의 액티비티를 구분하기 위해 사용된다. 

## 3.onActivityResult()
> onActivityResult() 메소드는 띄웠던 액티비티가 응답을 보내오면 그 응답을 처리하는 역할을 한다.

    [Reference]
    protected void onActivityResult(int requestCode, int resultCode, Intent intent)

이 메소드의 첫 번째 파라미터는 액티비티를 띄울 때 전달했던 코드와 같으므로 어떤 액티비티로부터 응답을 받은 것인지 구분할 때 사용한다.
두 번째 파라미터는 응답을 보내 온 액티비티로부터 전달된 값으로 임의의 코드이다.
세 번째 파라미터는 응답을 보내 온 액티비티로부터 전달한 인텐트로 필요한 데이터가 있을 때 인텐트에 데이터를 넣어 전달한다.