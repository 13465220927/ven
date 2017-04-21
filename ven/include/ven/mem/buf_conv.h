#pragma once

namespace ven {

  class BufConv
  {
  public:
    BufConv() {}

    virtual ~BufConv() {}

    // ��Ŷ�� Buf�� ������ ��Ŷ ���� ����
    virtual void set_size(ui32_t size) = 0;

    // ��Ŷ, Buf�� ����� ����
    virtual void serialize(Archive& ar) = 0;

    Buf make_buf(IMemPool& mpool)
    {
      // ũ�� ���
      Archive ar(Archive::Size);
      serialize(ar);

      ui32_t size = ar.size();
      set_size(size);
      if (size == 0) {
        return Buf();
      }

      // ���� �Ҵ�
      Buf buf = mpool.get(size);
      if (!buf) return buf;
      buf.len_ = size;

      // ���� ��Ŷ  ����
      ar.set(buf, Archive::Write);
      serialize(ar);
      return ar.buf();
    }

    void make_from(Buf& buf)
    {
      Archive ar;
      ar.set(buf, Archive::Read);
      serialize(ar);
    }

  };
}