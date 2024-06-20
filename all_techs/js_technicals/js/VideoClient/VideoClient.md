implement a video live stream client where you can query a httl or something for a manifest. The manifest is a dict of quality to list[url]. The url's can be used to download 10s video segments and whenever a video segment is ready its added to the end of the manifest list.

You are given the following classes, methods are all assumed to be implemented
```py
class VideoPlayer:
    def add_segment_to_buffer(self,  segment):
        pass

    def get_buffer_time_ms(self):
        pass

class Httl:
    def get_manifest(self, manifest_url) -> Dict[int: List[url]]:
        pass

    def start_download(self, download: Download):
        pass

    def is_download_complete(self, download: Download):
        pass

    def get_segment_from_download(self, download):
        pass

    def get_estimated_download_duration_ms(self, url):
        pass

    def get_estimated_download_duration_remaining_ms(self, url):
        pass
```

Implement this class:
```py 
class Client:
    STATIC_QUALITY = 5 # only used in Task 1
    
    def __init__(self, httl, videoplayer):
        pass

    # Called every 1ms, should manage downloading and call add_segment_to_buffer when necessary
    def on_tick(self):
        pass
```

## Parts
**Part 1:** Told to implement on_tick first with static quality. Keep downloading segments of quality 5.

**Part 2:** Then implement with dynamic quality, where we prioritize minimizing interruptions. If the current download takes more time than the total time of segments in the buffer, we get an interruption because we need to wait for the segment to download. In this case, you should cancel the current download and find one with a lower quality and shorter download time.

**Part 3:** Then maximise quality - always download the highest quality segment that can be downloaded without interruptions.

**Part 4:** Then minimise start up time - want there to be minimum time before a segment is in the buffer.