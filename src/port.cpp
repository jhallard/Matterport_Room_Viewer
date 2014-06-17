#include <iostream>
#include <pcl/visualization/pcl_visualizer.h>
#include <ctime>

#define VTK_EXCLUDE_STRSTREAM_HEADERS
#include <pcl/io/vtk_lib_io.h>

#define TYPE pcl::PointXYZ

int main (int argc, char** argv)
{
    pcl::PointCloud<TYPE>::Ptr cloud (new pcl::PointCloud<TYPE>);
    pcl::PolygonMesh mesh;

    // load the object file into a polygon mesh
    pcl::io::loadPolygonFileOBJ("../src/room.obj", mesh); 
    pcl::fromPCLPointCloud2(mesh.cloud, *cloud); 

    pcl::visualization::PCLVisualizer viewer ("Room Viewer");
    pcl::visualization::PointCloudColorHandlerCustom<TYPE> source_cloud_color_handler (cloud, 70, 50, 30); // Where 255,255,255 are R,G,B colors
    
    if(argc == 2)
        viewer.addPointCloud (cloud, source_cloud_color_handler, "Filtered Cloud");	// We add the point cloud to the viewer and pass the color handler
    
    else
         viewer.addPolygonMesh(mesh);// source_cloud_color_handler, "Filtered Cloud");    // We add the point cloud to the viewer and pass the color handler
    
    viewer.addCoordinateSystem (1.0, 0);
    viewer.setBackgroundColor(0.95, 0.95, 0.95, 0); // Setting background to a dark grey
    //viewer.setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "Filtered Cloud");
    //viewer.setPosition(800, 400); // Setting visualiser window position

    viewer.spin();

  return 0;
}

//#include <pcl/io/file_io.h>
/*#include <pcl/io/boost.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/obj_io.h>
#include <pcl/io/vtk_io.h>*/
/*#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include <iostream>

#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/console/parse.h>
#include <pcl/registration/ia_ransac.h>*/
/*#include "pcl/common/common.h"
#include "pcl/common/file_io.h"
#include "pcl/common/eigen.h"

#include <pcl/pcl_macros.h>
//#include <pcl/PolygonMesh.h>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

#include "pcl/common/common.h"
#include "pcl/common/transforms.h"

#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include <pcl/io/obj_io.h>*/