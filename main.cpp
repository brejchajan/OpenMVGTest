#include "sfm/sfm_data.hpp"
#include "sfm/sfm_data_io.hpp"

#include <string>

using namespace openMVG::sfm;
using namespace std;


int main(int argc, char *argv[])
{
    string sfm_data_path = "/Users/janbrejcha/data/adobe_intern/good_reconstruction/Lake_Tahoe_Brejcha_2017/results/openmvg_global_gps_perspective_pano_6_fov_60_akaze_high/components/43/reconstruction_global/sfm_data.bin";
    string sfm_data_xml_path ="/Users/janbrejcha/Downloads/sfmtest/sfm_data.json";
    SfM_Data data;

    if (!openMVG::sfm::Load(data, sfm_data_path,

                                        (ESfM_Data)(VIEWS | EXTRINSICS |
                                                    INTRINSICS | STRUCTURE)))
    {
        throw std::runtime_error("Unable to load sfm_data.");
    }
	return 0;
}
