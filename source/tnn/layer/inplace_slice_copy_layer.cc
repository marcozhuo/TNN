
// Tencent is pleased to support the open source community by making TNN available.
//
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#include <cmath>

#include "tnn/layer/base_layer.h"
#include "tnn/utils/dims_utils.h"

namespace TNN_NS {
DECLARE_LAYER(InplaceSliceCopy, LAYER_INPLACE_SLICE_COPY);

Status InplaceSliceCopyLayer::InferOutputDataType() {
    return BaseLayer::InferOutputDataType();
}

Status InplaceSliceCopyLayer::InferOutputShape(bool ignore_error) {
    BaseLayer::InferOutputShape(ignore_error);

    Blob* input_blob  = input_blobs_[0];
    Blob* output_blob = output_blobs_[0];
    auto dims         = input_blob->GetBlobDesc().dims;

    output_blob->GetBlobDesc().dims = dims;
    return TNN_OK;
}

REGISTER_LAYER(InplaceSliceCopy, LAYER_INPLACE_SLICE_COPY);

}  // namespace TNN_NS