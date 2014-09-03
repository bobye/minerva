#include <iostream>
#include "device.h"
#include "op/physical_fn.h"

namespace minerva {

Device::Device() {}

Device::Device(DeviceInfo info) {
  device_info_ = info;
}

DeviceInfo Device::GetInfo() {
  return device_info_;
}

void Device::Execute(std::vector<PhysicalData> inputs, const PhysicalOp Op) {
  std::cout << Op.compute_fn->Name() << std::endl;
  std::cout << device_info_.id << std::endl;
  std::vector<DataShard> inputShards;
  for (std::vector<PhysicalData>::iterator it = inputs.begin(); it != inputs.end(); ++ it) {
    uint64_t data_id = it->data_id;
    if (local_data_.find(data_id) == local_data_.end()) { // data not found locally
       uint64_t its_device_id = it->device_info.id;
       // create space
       //if ()
       //  data_store_.CreateData(data_id, DataStore::CPU, it.size.Prod(), 1);
       // data copy
       local_data_.insert(data_id);
    }
    inputShards.push_back(DataShard(*it));
  }
}

}
