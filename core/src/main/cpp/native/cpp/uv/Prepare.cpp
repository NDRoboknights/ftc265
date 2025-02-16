// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "wpi/uv/Prepare.h"

#include "wpi/uv/Loop.h"

namespace wpi::uv {

    std::shared_ptr <Prepare> Prepare::Create(Loop &loop) {
        auto h = std::make_shared<Prepare>(private_init{});
        int err = uv_prepare_init(loop.GetRaw(), h->GetRaw());
        if (err < 0) {
            loop.ReportError(err);
            return nullptr;
        }
        h->Keep();
        return h;
    }

    void Prepare::Start() {
        Invoke(&uv_prepare_start, GetRaw(), [](uv_prepare_t *handle) {
            Prepare &h = *static_cast<Prepare *>(handle->data);
            h.prepare();
        });
    }

}  // namespace wpi::uv
