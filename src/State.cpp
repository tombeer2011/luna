#include "State.h"

namespace lua
{
    State::State()
        : stack_(new Stack),
          data_pool_(new DataPool),
          module_loader_(new ModuleLoader),
          vm_(new VirtualMachine),
          global_table_(data_pool_->GetTable())
    {
        module_loader_->Init(this);
        vm_->Init(this, global_table_);
    }

    Stack * State::GetStack()
    {
        return stack_.get();
    }

    DataPool * State::GetDataPool()
    {
        return data_pool_.get();
    }

    ModuleLoader * State::GetModuleLoader()
    {
        return module_loader_.get();
    }

    VirtualMachine * State::GetVM()
    {
        return vm_.get();
    }
} // namespace lua
