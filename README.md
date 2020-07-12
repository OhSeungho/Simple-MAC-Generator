# Simple-MAC-Generator

C++ 언어를 기반으로 간단한 메시지 인증 코드 생성 프로그램을 구현해보았습니다. 기본적인 구성은 Client와 Attacker 중 선택하여 Server 쪽으로 메시지를 전달하는 가상의 시스템을 구성하였습니다. Client와 Attacker 두 상태 모두 동일한 메시지를 전달할 수 있으며, Attacker는 비정상적인 절차에 따른 임의의 공 격을 수행할 수 있다는 전제하 구성하였습니다.
  
HMAC 값은 SHA-256을 사용하여 생성하였습니다. C++ 표준 라이브러리에서 이를 지원하지 않기 때문에 외부에서 구성된 시스템을 가져와 사용하였습니다. SHA-256은 해시 함수 중에 하나로서, 해시의 결과가 256bit입니다. SHA-256 알고리즘은 해시 대상 메시지를 전처리하는 단계와 전처리 된 메시지를 바탕으로 해시를 계산하는 단계로 나뉩니다. 메시지 bit의 길이가 512의 배수가 되도록 padding을 추가하는 것이 전 처리 단계에서 수행합니다.

[C++ sha256](http://www.zedwood.com/article/cpp-sha256-function).

전처리가 끝난 512의 배수 bit 길이의 메시지를 512bit 단위로 쪼개서 여러 개의 chunk를 만듭니다. 이후 이러한 chunk 들을 차례대로 순회하면서 특정 연산을 수행하여 최종적인 hash 값을 계산해내게 됩니다.

![image](https://user-images.githubusercontent.com/51220344/87248226-598ef880-c493-11ea-80f4-bd5fdb100bc7.png)
