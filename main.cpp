#include "openMVG/sfm/sfm_data.hpp"
#include "openMVG/sfm/sfm_data_io.hpp"

#include <string>

using namespace openMVG::sfm;
using namespace std;


int main(int argc, char *argv[])
{
    string sfm_data_path = argv[1];
    SfM_Data data;

    //VIEWS | EXTRINSICS | INTRINSICS | STRUCTURE
    if (!Load(data, sfm_data_path, (ESfM_Data)(ALL)))
    {
        throw std::runtime_error("Unable to load sfm_data.");
    }
	return 0;
}
