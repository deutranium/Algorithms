--- Sort an array using the radix sort algorithm.
--- @param t table
--- @return table
local function radixSort(t)
    local n = #t
    local max = 0
    for i = 1, n do
        if t[i] > max then
            max = t[i]
        end
    end
    local exp = 1
    while max / exp > 0 do
        local counts = {}
        for i = 1, n do
            local digit = math.floor(t[i] / exp) % 10
            counts[digit] = (counts[digit] or 0) + 1
        end
        for i = 1, 9 do
            counts[i] = (counts[i] or 0) + (counts[i - 1] or 0)
        end
        local sorted = {}
        for i = n, 1, -1 do
            local digit = math.floor(t[i] / exp) % 10
            sorted[counts[digit]] = t[i]
            counts[digit] = counts[digit] - 1
        end
        for i = 1, n do
            t[i] = sorted[i]
        end
        exp = exp * 10
    end
    return t
end

return radixSort