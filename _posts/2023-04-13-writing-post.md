---
layout: single
title: "DirectX11 Error 메모"
---

### DirectX11 0xC0000005 에러 문제가 난 경우.

프로세스가 동작하면서 접근이 허용되지 않은 메모리 공간에 접근하는 문제.
- 할당한 메모리 공간을 넘어서는 경우
- 애초에 할당이 되지 않은 경우  


DX11을 배우면서 ID3DBlob 포인터를 이용하여 CreateVertexShader로 vertex shader를 만들고,
해당 포인터를 이용하여 CreateInputLayout으로 input layout을 만들어 줄 때 에러가 발생했다.  


위의 두 처리를 한 이후에
```cpp
pVertexShaderBlob->Release(); 
```
을 사용하여 해제를 해줘야 한다. (pVertexShaderBlob은 임의로 지은 변수명)  


vertex shader가 제대로 만들어지지 않은 경우에도 오류 처리로 
```cpp
if (FAILED(hr))
{
  pVertexShaderBlob->Release();
  return hr;
}
```
위 처럼 release를 해줘야 한다. (HRESULT hr)  


하지만 제대로 만들어졌음에도
```cpp
pVertexShaderBlob->Release();
```
처리를 해버리고 input layout을 만드려하니 
이미 해제된 포인터에 값을 할당할 때 에러가 발생한 듯하다. (아마도...?)
