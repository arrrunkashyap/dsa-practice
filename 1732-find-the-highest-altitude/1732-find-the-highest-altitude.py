class Solution:
    def largestAltitude(self, gain):
        currentAltitude = 0
        highestPoint = 0

        for altitudeGain in gain:
            currentAltitude += altitudeGain
            highestPoint = max(highestPoint, currentAltitude)

        return highestPoint