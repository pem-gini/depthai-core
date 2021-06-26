#pragma once

#include <unordered_map>
#include <vector>

#include "depthai-shared/datatype/RawEdgeDetectorConfig.hpp"
#include "depthai/pipeline/datatype/Buffer.hpp"

namespace dai {

/**
 * EdgeDetectorConfig message. Carries sobel edge filter config.
 */
class EdgeDetectorConfig : public Buffer {
    std::shared_ptr<RawBuffer> serialize() const override;
    RawEdgeDetectorConfig& cfg;

   public:
    /**
     * Construct EdgeDetectorConfig message.
     */
    EdgeDetectorConfig();
    explicit EdgeDetectorConfig(std::shared_ptr<RawEdgeDetectorConfig> ptr);
    virtual ~EdgeDetectorConfig() = default;

    /**
     * Set sobel filter horizontal and vertical 3x3 kernels
     * @param horizontalKernel Used for horizontal gradiant computation in 3x3 Sobel filter
     * @param verticalKernel Used for vertical gradiant computation in 3x3 Sobel filter
     */
    void setSobelFilterKernels(const std::vector<std::vector<int>>& horizontalKernel, const std::vector<std::vector<int>>& verticalKernel);

    /**
     * Retrieve configuration data for EdgeDetector
     * @returns Vector of configuration parameters for ROIs (region of interests)
     */
    EdgeDetectorConfigData getConfigData() const;
};

}  // namespace dai
