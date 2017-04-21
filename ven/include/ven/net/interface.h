#pragma once

namespace ven {

  class ISessionTCP
  {
  public:

    // ���� ��Ŷ ������
    virtual bool get_packet_size(byte_t* buf, const ui32_t len, ui32_t& packet_size) = 0;

    // �̻��� ��Ŷ �������� ��� ���� ���� ����
    virtual bool is_valid_packet_size(ui32_t size) = 0;

    // ��Ŷ�� ��� ������(bytes)
    virtual ui32_t header_size() = 0;

    // ���� ���� ũ��
    virtual ui32_t receive_buffer_size() = 0;

    // ����
    virtual void on_conn() = 0;

    // ���� ����
    virtual void on_disc(ui32_t err) = 0;

    // ����
    virtual void on_recv(ven::Buf& buf) = 0;
  };


  class ISessionUDP
  {
  public:

    /*
    �����Ϸ��� udp ��Ŷ ũ�⺸�� recv �ɸ��� ���� ũ�Ⱑ ������
    GQCS recv ���� ERROR_NO_DATA(232) �߻��ϹǷ�
    ����ϴ� UDP ��Ŷ�� �ִ� ũ�⸦ ����־�� ��
    */
    virtual ui32_t recv_buf_remaining_size_to_exchange() = 0;

    // ���� ���� ũ��
    virtual ui32_t receive_buffer_size() = 0;

    // ����
    virtual void on_recv(Buf& buf, Addr& addr) = 0;

  };


  class SessionTCP;
  class ISessionPool
  {
  public:
    ISessionPool() {}
    ~ISessionPool() {}

    virtual SessionTCP* pop() = 0;
    virtual void push(SessionTCP* s) = 0;
  };


  class IAcceptor
  {
  public:
    IAcceptor() {}
    ~IAcceptor() {}

    virtual void disconnected(SessionTCP* s) = 0;
  };


  class SvrState;
  class IServer
  {
  public:
    IServer() {}
    virtual ~IServer() {}

    virtual bool run() = 0;
    virtual void stop() = 0;
    virtual void state(SvrState& s) = 0;
  };

}
