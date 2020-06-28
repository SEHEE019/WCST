# Service & Broadcast
- 액티비티
- 서비스
- 브로드캐스트 수신자
- 컨텐트 프로바이더

## 1. 서비스
- 서비스는 백그라운드에서 실행
- AndroidManifest.xml 안에 < service > 태그를 이용하여 선언
  - 액티비티와 마찬가지로 시스템에서 관리하는 구성요소이기 때문
- 서비스 시작 및 중단과 관련된 메소드
  - xml 파일이 존재하지 않고 java 파일로 동작
  - 서비스는 강제종료가 되더라도 자동으로 다시 실행이 됨
  - Context.startService(): 특정 버튼을 누르면 서비스를 시작하도록 함
  - Context.bindService()
  - stopService(...)
  - unbindService(...)
- 다른 구성 요소들처럼 main thread에서 동작
  - CPU과부하 상태나 대기 상태(blocking)상태를 필요로 할 땐 thread를 새로 만들어 주어야 함

## 2. 브로드캐스트 수신자
- 메시지를 전달할 수 있는 방법
- 기기에서 먼저 받고 어플리케이션으로 인텐트를 통해 정보를 던져줌
- 이 때 브로드캐스트 수신자를 통해 인텐트를 받음
