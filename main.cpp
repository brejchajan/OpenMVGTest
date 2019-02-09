#include "sfm/sfm_data.hpp"
#include "sfm/sfm_data_io.hpp"

#include <string>

using namespace openMVG::sfm;
using namespace std;


int main(int argc, char *argv[])
{
    string sfm_data_path = argv[1];
    SfM_Data data;

    if (!openMVG::sfm::Load(data, sfm_data_path,

                                        (ESfM_Data)(VIEWS | EXTRINSICS |
                                                    INTRINSICS | STRUCTURE)))
    {
        throw std::runtime_error("Unable to load sfm_data.");
    }
	return 0;
}
