#pragma once

#include "render_settings.hpp"
#include "export.hpp"

#include <Geode/Result.hpp>

#include <vector>
#include <string>
#include <memory>
#include <unordered_map>

class AVFormatContext;
class AVCodec;
class AVStream;
class AVCodecContext;
class AVBufferRef;
class AVFrame;
class AVPacket;
class SwsContext;
class AVFilterContext;
class AVFilter;
class AVFilterGraph;

BEGIN_FFMPEG_NAMESPACE_V

class FFMPEG_API_DLL Recorder {
private:
    class Impl {
    public:
        AVFormatContext* m_formatContext = nullptr;
        const AVCodec* m_codec = nullptr;
        AVStream* m_videoStream = nullptr;
        AVCodecContext* m_codecContext = nullptr;
        AVBufferRef* m_hwDevice = nullptr;
        AVFrame* m_frame = nullptr;
        AVFrame* m_convertedFrame = nullptr;
        AVFrame* m_filteredFrame = nullptr;
        AVPacket* m_packet = nullptr;
        SwsContext* m_swsCtx = nullptr;
        AVFilterGraph* m_filterGraph = nullptr;
        AVFilterContext* m_buffersrcCtx = nullptr;
        AVFilterContext* m_buffersinkCtx = nullptr;
        AVFilterContext* m_colorspaceCtx = nullptr;
        AVFilterContext* m_vflipCtx = nullptr;

        size_t m_frameCount = 0;
        size_t m_expectedSize = 0;
        bool m_init = false;

        geode::Result<> init(const RenderSettings& settings);
        void stop();
        geode::Result<> writeFrame(const std::vector<uint8_t>& frameData);
        geode::Result<> filterFrame(AVFrame* inputFrame, AVFrame* outputFrame);
    };

    std::unique_ptr<Impl> m_impl = nullptr;

public:
    geode::Result<> init(const RenderSettings& settings) {
        m_impl = std::make_unique<Impl>();
        return m_impl->init(settings);
    }

    void stop() const { m_impl->stop(); }

    geode::Result<> writeFrame(const std::vector<uint8_t>& frameData) const {
        return m_impl->writeFrame(frameData);
    }

    static std::vector<std::string> getAvailableCodecs();

private:
    geode::Result<> filterFrame(AVFrame* inputFrame, AVFrame* outputFrame) const {
        return m_impl->filterFrame(inputFrame, outputFrame);
    }
};

END_FFMPEG_NAMESPACE_V
