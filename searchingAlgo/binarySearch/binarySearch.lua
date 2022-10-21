--[[
    This can be run in vanilla Lua!

    $ lua ./binarySearch.lua
]]

--- search an element in array with binary search
--- @param arr table list of integer
--- @param x number int we want to search
--- @param left number low index of array
--- @param right number high index of array
local function binarySearch(arr, x, left, right)
    --- mid index of selected array
    --- @type number
    local mid = math.floor(left + (right - left) / 2) + 1 --- +1 because lua starts table at [1] and not [0]

    --- return -1 if x not in array
    if mid >= #arr or right < 1 then
        return -1
    end

    if x == arr[mid] then --- if value is equal to element in array mid index, return the index
        return mid
    elseif x > arr[mid] then --- if value is bigger than elemnt in array mid, search in the right half
        return binarySearch(arr, x, mid + 1, right)
    else --- otherwise search for the left half
        return binarySearch(arr, x, left, mid - 1)
    end
end

local arr = { 1, 5, 2, 3, 4, 5, 6, 7, 8, 9 }
local arr2 = { 1, 5, 2, 3, 4, 100, 6, 7, 11, 9 }

local x = 0
local x1 = 1

do
    print(binarySearch(arr, x, 0, #arr))
    print(binarySearch(arr2, x1, 0, #arr))
end