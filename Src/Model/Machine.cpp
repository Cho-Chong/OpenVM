#include "Machine.h"

Model::Machine::Machine(unsigned int max_code_size, unsigned int max_data_size) : Program(max_code_size),
Data(max_data_size)
{

}

Model::Machine::~Machine()
{
}
