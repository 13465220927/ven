#pragma once

namespace ven {

  class Mem
    : public Next<Mem>
  {
  public:
    byte_t* addr_ = nullptr;  // �Ҵ���� �޸�
    unit_t unit_ = 0; // �Ҵ���� �޸� ũ��

    IMemPool* mpool_ = nullptr;
    ui32_t ref_ = 0;

  public:
    Mem() = default;

    void add_ref()
    {
      InterlockedIncrement(&ref_);
    }

    void rel_ref()
    {
      if (InterlockedDecrement(&ref_) == 0) {
        mpool_->ret(this);
      }
    }

  };

}