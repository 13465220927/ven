#pragma once

namespace ven {
  
  class SvrState {
  public:
    ui32_t total_ = 0;
    ui32_t free_ = 0;
    ui32_t conn_ = 0;
    ui32_t accepting_ = 0; // accept �ɷ��ִ� ����
  };

  class SOVState {
  public:
    ui32_t total_ = 0;
    ui32_t free_ = 0;
  };

  class NetState {
  public:
    MemState mem_;
    SOVState sov_;
    AddrMap<SvrState> svr_;

    void print()
    {
      mem_.print();
      printf(
        "  sov - total: %u, free: %u, use: %u\n",
        sov_.total_, sov_.free_, sov_.total_ - sov_.free_);

      for (auto& kv : svr_) {
        const Addr& addr = kv.first;
        SvrState& s = kv.second;
        printf(
          "  %s:%hd - total: %u, free:%u, conn:%u, accepting:%u\n",
          addr.ip_, addr.port_, s.total_, s.free_, s.conn_, s.accepting_
        );
      }
    }

  };

}
