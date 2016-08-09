#ifndef PONCTUALCCTAG_HPP
#define	PONCTUALCCTAG_HPP

#include <cctag/Params.hpp>
#include <cctag/CCTagMarkersBank.hpp>

#include <boost/ptr_container/ptr_list.hpp>
#include <boost/gil/gil_all.hpp>

#include <opencv2/core/core.hpp>

namespace cctag {

namespace logtime {
struct Mgmt;
}
  
typedef int MarkerID;

class ICCTag
{
public:

	ICCTag()
		: _x( 0.f )
		, _y( 0.f )
		, _id( -1 )
	{ }
                
        virtual float x() const = 0;
        virtual float y() const = 0;
        virtual MarkerID id() const = 0;
        virtual int getStatus() const = 0;

	virtual ~ICCTag() {}

protected:
	float _x;
	float _y;
	MarkerID _id;
        int _status; // WARNING: only markers with status == 1 are the valid ones. (status available via getStatus()) 
                     // A marker correctly detected and identified has a status 1.
                     // Otherwise, it can be detected but not correctly identified.
};

/**
 * @brief Perform the CCTag detection on a gray scale image
 * 
 * @param[out] markers Detected markers. WARNING: only markers with status == 1 are the valid ones. (status available via getStatus()) 
 * @param[in] frame A frame number. Can be anything (e.g. 0).
 * @param[in] graySrc Gray scale input image.
 * @param[in] nRings Number of CCTag rings.
 * @param[in] parameterFile Path to a parameter file. If not provided default parameters will be used.
 * @param[in] cctagBankFilename Path to the cctag bank. If not provided, radii will be the ones associated to the CCTags contained in the
 * markersToPrint folder.
 */
void cctagDetection(
      boost::ptr_list<ICCTag> & markers,
      const std::size_t frame,
      const cv::Mat & graySrc,
      logtime::Mgmt* durations = 0,
      const std::size_t nRings = 3,
      const std::string & parameterFile = "",
      const std::string & cctagBankFilename = "");

void cctagDetection(
      boost::ptr_list<ICCTag> & markers,
      const std::size_t frame,
      const cv::Mat & graySrc,
      const cctag::Parameters & params,
      logtime::Mgmt* durations = 0,
      const CCTagMarkersBank * bank = NULL);

}

#endif	/* PONCTUALCCTAG_HPP */

