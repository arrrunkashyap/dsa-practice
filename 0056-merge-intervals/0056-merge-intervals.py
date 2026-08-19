class Solution:
    def merge(self, intervals):
        intervals.sort()

        result = []

        for start, end in intervals:
            # No overlap
            if not result or result[-1][1] < start:
                result.append([start, end])

            # Overlap
            else:
                result[-1][1] = max(result[-1][1], end)

        return result    