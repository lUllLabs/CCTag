#ifndef _CCTAG_IMAGEPYRAMID_HPP
#define	IMAGEPYRAMID_HPP

#include <cctag/Level.hpp>

#include <opencv2/opencv.hpp>

#include <stdint.h>
#include <cstddef>
#include <vector>

namespace cctag {

class ImagePyramid
{
public:
  ImagePyramid();
  
  ImagePyramid( const std::size_t width, const std::size_t height, const std::size_t nLevels );
  
  ~ImagePyramid();

  Level* getLevel( const std::size_t level ) const;
  
  std::size_t getNbLevels() const;
  
  void build(const cv::Mat & src);
  void output();

private:
  std::vector<Level*> _levels;
};

}

#endif	/* _CCTAG_IMAGEPYRAMID_HPP */

