#pragma once

namespace ven {

  class NetErrorReceiver;
  class NetConf
  {
  public:
    ui32_t thread_cnt_ = 0; // 0�� ��� (cpu core * 2) + 1
    MemPool* mpool_ = nullptr;  // nullptr�� ��� Net ��ü�ȿ��� ����

    ui32_t sov_pool_init_size_ = 300; // send overrapped ��ü ���� ��
    ui32_t sov_pool_step_size_ = 100; // send overrapped ��ü ���� ��(���� ��)
    ui32_t sov_pool_arr_size_ = 1000; // send overrapped ��ü�� �ִ� ��ƺ��� send ��

    NetErrorReceiver* err_rcv_ = nullptr; // ���� ���ſ� ��ü
  };


  class ServerConf
  {
  public:
    Addr addr_ = { "0.0.0.0", 12001 };  // listen ip,port
    ui32_t accept_cnt_ = 200;  // accept �ɾ�� ���� ��
    ui32_t session_pre_cnt_ = 200;  // �̸� ������ ���� ��
    ui32_t session_inc_cnt_ = 100;  // ���� ���� ����
    ui32_t session_max_cnt_ = 20000;  // �ִ� ���� ��
    void* session_user_data_ = nullptr; // ���� ��ü�� ������ ����� ������ (user_data() �޼ҵ�� ���ٰ���)
  };

  class IOCP;
  class SOVPool;
  class NetData
  {
  public:
    IOCP* iocp_ = nullptr;
    MemPool* mpool_ = nullptr;
    SOVPool* sov_pool_ = nullptr;
    IAcceptor* acpt_ = nullptr;
  };


  class UserData
  {
  private:
    void* user_data_ = nullptr;

  protected:
    void* user_data()
    {
      return user_data_;
    }

    void set_user_data(void* user_data)
    {
      user_data_ = user_data;
    }
  };

}
